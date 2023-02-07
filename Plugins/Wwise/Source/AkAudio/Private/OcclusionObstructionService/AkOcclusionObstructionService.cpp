/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


/*=============================================================================
AkOcclusionObstructionService.cpp:
=============================================================================*/

#include "OcclusionObstructionService/AkOcclusionObstructionService.h"
#include "AkAudioDevice.h"
#include "AkComponent.h"
#include "AkSpatialAudioHelper.h"
#include "AkAcousticPortal.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Components/PrimitiveComponent.h"
#include "Async/Async.h"
#include "GameFramework/PlayerController.h"


#define AK_DEBUG_OCCLUSION_PRINT 0
#if AK_DEBUG_OCCLUSION_PRINT
static int framecounter = 0;
#endif

#define AK_DEBUG_OCCLUSION 0
#if AK_DEBUG_OCCLUSION
#include "DrawDebugHelpers.h"
#endif



FAkListenerOcclusionObstruction::FAkListenerOcclusionObstruction(float in_TargetValue, float in_CurrentValue)
	: CurrentValue(in_CurrentValue)
	, TargetValue(in_TargetValue)
	, Rate(0.0f)
{}

void FAkListenerOcclusionObstruction::SetTarget(float in_TargetValue)
{
	TargetValue = FMath::Clamp(in_TargetValue, 0.0f, 1.0f);

	const float UAkComponent_OCCLUSION_FADE_RATE = 2.0f; // from 0.0 to 1.0 in 0.5 seconds
	Rate = FMath::Sign(TargetValue - CurrentValue) * UAkComponent_OCCLUSION_FADE_RATE;
}

bool FAkListenerOcclusionObstruction::Update(float DeltaTime)
{
	auto OldValue = CurrentValue;
	if (OldValue != TargetValue)
	{
		const auto NewValue = OldValue + Rate * DeltaTime;
		if (OldValue > TargetValue)
			CurrentValue = FMath::Clamp(NewValue, TargetValue, OldValue);
		else
			CurrentValue = FMath::Clamp(NewValue, OldValue, TargetValue);

		AKASSERT(CurrentValue >= 0.f && CurrentValue <= 1.f);
		return true;
	}

	return false;
}

bool FAkListenerOcclusionObstruction::ReachedTarget()
{
	return CurrentValue == TargetValue;
}

//=====================================================================================
// FAkListenerOcclusionObstructionPair
//=====================================================================================

FAkListenerOcclusionObstructionPair::FAkListenerOcclusionObstructionPair()
{
	SourceRayCollisions.AddZeroed(NUM_BOUNDING_BOX_TRACE_POINTS);
	ListenerRayCollisions.AddZeroed(NUM_BOUNDING_BOX_TRACE_POINTS);

	SourceTraceHandles.AddDefaulted(NUM_BOUNDING_BOX_TRACE_POINTS);
	ListenerTraceHandles.AddDefaulted(NUM_BOUNDING_BOX_TRACE_POINTS);
}

bool FAkListenerOcclusionObstructionPair::Update(float DeltaTime)
{
	if (CurrentCollisionCount != GetCollisionCount())
	{
		CurrentCollisionCount = GetCollisionCount();
		const float ratio = (float)CurrentCollisionCount / NUM_BOUNDING_BOX_TRACE_POINTS;
		Occ.SetTarget(ratio);
		Obs.SetTarget(ratio);
	}
	const bool bObsChanged = Obs.Update(DeltaTime);
	const bool bOccChanged = Occ.Update(DeltaTime);
	return bObsChanged || bOccChanged;
}

void FAkListenerOcclusionObstructionPair::Reset()
{
	for (int i = 0; i < NUM_BOUNDING_BOX_TRACE_POINTS; ++i)
	{
		SourceRayCollisions[i] = ListenerRayCollisions[i] = false;
	}
}

bool FAkListenerOcclusionObstructionPair::ReachedTarget()
{
	return Obs.ReachedTarget() && Occ.ReachedTarget();
}

void FAkListenerOcclusionObstructionPair::AsyncTraceFromSource(const FVector& SourcePosition, const FVector& EndPosition, int BoundingBoxPointIndex, ECollisionChannel CollisionChannel, UWorld* World, const FCollisionQueryParams& CollisionParams)
{
	ensure(BoundingBoxPointIndex < NUM_BOUNDING_BOX_TRACE_POINTS);
	// Check that we're not stacking another async trace on top of one that hasn't completed yet.
	if (!World->IsTraceHandleValid(SourceTraceHandles[BoundingBoxPointIndex], false))
	{
		SourceTraceHandles[BoundingBoxPointIndex] = World->AsyncLineTraceByChannel(EAsyncTraceType::Single, SourcePosition, EndPosition, CollisionChannel, CollisionParams);
	}
}
void FAkListenerOcclusionObstructionPair::AsyncTraceFromListener(const FVector& ListenerPosition, const FVector& EndPosition, int BoundingBoxPointIndex, ECollisionChannel CollisionChannel, UWorld* World, const FCollisionQueryParams& CollisionParams)
{
	ensure(BoundingBoxPointIndex < NUM_BOUNDING_BOX_TRACE_POINTS);
	// Check that we're not stacking another async trace on top of one that hasn't completed yet.
	if (!World->IsTraceHandleValid(ListenerTraceHandles[BoundingBoxPointIndex], false))
	{
		ListenerTraceHandles[BoundingBoxPointIndex] = World->AsyncLineTraceByChannel(EAsyncTraceType::Single, ListenerPosition, EndPosition, CollisionChannel, CollisionParams);
	}
}

int FAkListenerOcclusionObstructionPair::GetCollisionCount()
{
	int CollisionCount = 0;
	for (int i = 0; i < NUM_BOUNDING_BOX_TRACE_POINTS; ++i)
	{
		CollisionCount += (SourceRayCollisions[i] || ListenerRayCollisions[i]) ? 1 : 0;
	}
	return CollisionCount;
}

void FAkListenerOcclusionObstructionPair::CheckTraceResults(UWorld* World)
{
	CheckListenerTraceHandles(World);
	CheckSourceTraceHandles(World);
}

void FAkListenerOcclusionObstructionPair::CheckListenerTraceHandles(UWorld* World)
{
	for (int BoundingBoxPointIndex = 0; BoundingBoxPointIndex < NUM_BOUNDING_BOX_TRACE_POINTS; ++BoundingBoxPointIndex)
	{
		if (ListenerTraceHandles[BoundingBoxPointIndex]._Data.FrameNumber != 0)
		{
			FTraceDatum OutData;
			if (World->QueryTraceData(ListenerTraceHandles[BoundingBoxPointIndex], OutData))
			{
				ListenerTraceHandles[BoundingBoxPointIndex]._Data.FrameNumber = 0;
				ListenerRayCollisions[BoundingBoxPointIndex] = OutData.OutHits.Num() > 0;
			}
		}
	}
}

void FAkListenerOcclusionObstructionPair::CheckSourceTraceHandles(UWorld* World)
{
	for (int BoundingBoxPointIndex = 0; BoundingBoxPointIndex < NUM_BOUNDING_BOX_TRACE_POINTS; ++BoundingBoxPointIndex)
	{
		if (SourceTraceHandles[BoundingBoxPointIndex]._Data.FrameNumber != 0)
		{
			FTraceDatum OutData;
			if (World->QueryTraceData(SourceTraceHandles[BoundingBoxPointIndex], OutData))
			{
				SourceTraceHandles[BoundingBoxPointIndex]._Data.FrameNumber = 0;
				SourceRayCollisions[BoundingBoxPointIndex] = OutData.OutHits.Num() > 0;
			}
		}
	}
}

//=====================================================================================
// AkOcclusionObstructionService
//=====================================================================================

void AkOcclusionObstructionService::_Init(UWorld* in_world, float in_refreshInterval)
{
	if (in_refreshInterval > 0 && in_world != nullptr)
		LastObstructionOcclusionRefresh = in_world->GetTimeSeconds() + FMath::RandRange(0.0f, in_refreshInterval);
	else
		LastObstructionOcclusionRefresh = -1;

}

void AkOcclusionObstructionService::RefreshObstructionOcclusion(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, const float DeltaTime, float OcclusionRefreshInterval)
{
	auto AudioDevice = FAkAudioDevice::Get();

	// Fade the active occlusions
	bool StillClearingObsOcc = false;
	for (auto It = ListenerInfoMap.CreateIterator(); It; ++It)
	{
		AkGameObjectID Listener = It->Key;

		if (in_Listeners.Find((UAkComponent*)Listener) == nullptr)
		{
			It.RemoveCurrent();
			continue;
		}

		FAkListenerOcclusionObstructionPair& ObsOccPair = It->Value;
		ObsOccPair.CheckTraceResults(Actor->GetWorld());
		if (ObsOccPair.Update(DeltaTime) && AudioDevice)
		{
			SetOcclusionObstruction(Listener, ObsOccPair.Obs.CurrentValue);
		}

		if (ClearingOcclusionObstruction)
		{
			StillClearingObsOcc |= !ObsOccPair.ReachedTarget();
		}
	}

	if (ClearingOcclusionObstruction)
	{
		ClearingOcclusionObstruction = StillClearingObsOcc;
		return;
	}

	// Compute occlusion only when needed.
	// Have to have "LastObstructionOcclusionRefresh == -1" because GetWorld() might return nullptr in UAkComponent's constructor,
	// preventing us from initializing it to something smart.
	const UWorld* CurrentWorld = Actor ? Actor->GetWorld() : nullptr;
	if (CurrentWorld)
	{
		float CurrentTime = CurrentWorld->GetTimeSeconds();
		if (CurrentTime < LastObstructionOcclusionRefresh && LastObstructionOcclusionRefresh - CurrentTime > OcclusionRefreshInterval)
		{
			// Occlusion refresh interval was made shorter since the last refresh, we need to re-distribute the next random calculation
			LastObstructionOcclusionRefresh = CurrentTime + FMath::RandRange(0.0f, OcclusionRefreshInterval);
		}

		if (LastObstructionOcclusionRefresh == -1 || (CurrentTime - LastObstructionOcclusionRefresh) >= OcclusionRefreshInterval)
		{
			LastObstructionOcclusionRefresh = CurrentTime;
			for (auto& Listener : in_Listeners)
			{
				auto& MapEntry = ListenerInfoMap.FindOrAdd(Listener->GetAkGameObjectID());
				MapEntry.Position = Listener->GetPosition();
			}
			CalculateObstructionOcclusionValues(in_Listeners, SourcePosition, Actor, RoomID, in_collisionChannel);
		}
	}
}

void AkOcclusionObstructionService::CalculateObstructionOcclusionValues(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, bool bAsync /* = true */)
{
	auto CurrentWorld = Actor->GetWorld();
	if (!CurrentWorld)
		return;

	static const FName NAME_SoundOcclusion = TEXT("SoundOcclusion");
	FCollisionQueryParams CollisionParams(NAME_SoundOcclusion, true, Actor);
	auto PlayerController = GEngine->GetFirstLocalPlayerController(CurrentWorld);
	if (PlayerController)
		CollisionParams.AddIgnoredActor(PlayerController->GetPawn());

	for (auto& Listener : in_Listeners)
	{
		if (RoomID != Listener->GetSpatialAudioRoom())
			continue;

		auto MapEntry = ListenerInfoMap.Find(Listener->GetAkGameObjectID());
		if (MapEntry == nullptr)
			continue;

		const FVector ListenerPosition = MapEntry->Position;

		FHitResult OutHit;
		const bool bNowOccluded = CurrentWorld->LineTraceSingleByChannel(OutHit, SourcePosition, ListenerPosition, in_collisionChannel, CollisionParams);

		if (bNowOccluded)
		{
			FBox BoundingBox;
			AActor* HitActor = AkSpatialAudioHelper::GetActorFromHitResult(OutHit);
			if (HitActor)
			{
				BoundingBox = HitActor->GetComponentsBoundingBox();
			}
			else if (OutHit.Component.IsValid())
			{
				BoundingBox = OutHit.Component->Bounds.GetBox();
			}
			// Translate the impact point to the bounding box of the obstacle
			const FVector Points[] =
			{
				FVector(OutHit.ImpactPoint.X, BoundingBox.Min.Y, BoundingBox.Min.Z),
				FVector(OutHit.ImpactPoint.X, BoundingBox.Min.Y, BoundingBox.Max.Z),
				FVector(OutHit.ImpactPoint.X, BoundingBox.Max.Y, BoundingBox.Min.Z),
				FVector(OutHit.ImpactPoint.X, BoundingBox.Max.Y, BoundingBox.Max.Z),

				FVector(BoundingBox.Min.X, OutHit.ImpactPoint.Y, BoundingBox.Min.Z),
				FVector(BoundingBox.Min.X, OutHit.ImpactPoint.Y, BoundingBox.Max.Z),
				FVector(BoundingBox.Max.X, OutHit.ImpactPoint.Y, BoundingBox.Min.Z),
				FVector(BoundingBox.Max.X, OutHit.ImpactPoint.Y, BoundingBox.Max.Z),

				FVector(BoundingBox.Min.X, BoundingBox.Min.Y, OutHit.ImpactPoint.Z),
				FVector(BoundingBox.Min.X, BoundingBox.Max.Y, OutHit.ImpactPoint.Z),
				FVector(BoundingBox.Max.X, BoundingBox.Min.Y, OutHit.ImpactPoint.Z),
				FVector(BoundingBox.Max.X, BoundingBox.Max.Y, OutHit.ImpactPoint.Z)
			};

			if (bAsync)
			{
				for (int PointIndex = 0; PointIndex < NUM_BOUNDING_BOX_TRACE_POINTS; ++PointIndex)
				{
					auto Point = Points[PointIndex];
					MapEntry->AsyncTraceFromListener(ListenerPosition, Point, PointIndex, in_collisionChannel, CurrentWorld, CollisionParams);
					MapEntry->AsyncTraceFromSource(SourcePosition, Point, PointIndex, in_collisionChannel, CurrentWorld, CollisionParams);
				}
			}
			else
			{
				// Compute the number of "second order paths" that are also obstructed. This will allow us to approximate
				// "how obstructed" the source is.
				int32 NumObstructedPaths = 0;
				for (const auto& Point : Points)
				{
					if (CurrentWorld->LineTraceSingleByChannel(OutHit, ListenerPosition, Point, in_collisionChannel, CollisionParams) ||
						CurrentWorld->LineTraceSingleByChannel(OutHit, SourcePosition, Point, in_collisionChannel, CollisionParams))
						++NumObstructedPaths;
				}
				// Modulate occlusion by blocked secondary paths. 
				const float ratio = (float)NumObstructedPaths / NUM_BOUNDING_BOX_TRACE_POINTS;
				MapEntry->Occ.SetTarget(ratio);
				MapEntry->Obs.SetTarget(ratio);
			}

#if AK_DEBUG_OCCLUSION
			check(IsInGameThread());
			// Draw bounding box and "second order paths"
			//UE_LOG(LogAkAudio, Log, TEXT("Target Occlusion level: %f"), ListenerOcclusionInfo[ListenerIdx].TargetValue);
			FlushPersistentDebugLines(CurrentWorld);
			FlushDebugStrings(CurrentWorld);
			DrawDebugBox(CurrentWorld, BoundingBox.GetCenter(), BoundingBox.GetExtent(), FColor::White, false, 4);
			DrawDebugPoint(CurrentWorld, ListenerPosition, 10.0f, FColor(0, 255, 0), false, 4);
			DrawDebugPoint(CurrentWorld, SourcePosition, 10.0f, FColor(0, 255, 0), false, 4);
			DrawDebugPoint(CurrentWorld, OutHit.ImpactPoint, 10.0f, FColor(0, 255, 0), false, 4);

			for (int32 i = 0; i < NUM_BOUNDING_BOX_TRACE_POINTS; i++)
			{
				DrawDebugPoint(CurrentWorld, Points[i], 10.0f, FColor(255, 255, 0), false, 4);
				DrawDebugString(CurrentWorld, Points[i], FString::Printf(TEXT("%d"), i), nullptr, FColor::White, 4);
				DrawDebugLine(CurrentWorld, Points[i], ListenerPosition, FColor::Cyan, false, 4);
				DrawDebugLine(CurrentWorld, Points[i], SourcePosition, FColor::Cyan, false, 4);
			}
			FColor LineColor = FColor::MakeRedToGreenColorFromScalar(1.0f - MapEntry->Occ.TargetValue);
			DrawDebugLine(CurrentWorld, ListenerPosition, SourcePosition, LineColor, false, 4);
#endif // AK_DEBUG_OCCLUSION
		}
		else
		{
			MapEntry->Occ.SetTarget(0.0f);
			MapEntry->Obs.SetTarget(0.0f);
			MapEntry->Reset();
		}
	}
}

void AkOcclusionObstructionService::SetObstructionOcclusion(const UAkComponentSet& in_Listeners, AkRoomID RoomID)
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (!AkAudioDevice)
		return;

	for (auto& Listener : in_Listeners)
	{
		if (RoomID != Listener->GetSpatialAudioRoom())
			continue;

		auto MapEntry = ListenerInfoMap.Find(Listener->GetAkGameObjectID());

		if (MapEntry == nullptr)
			continue;

		MapEntry->Occ.CurrentValue = MapEntry->Occ.TargetValue;
		SetOcclusionObstruction(Listener->GetAkGameObjectID(), MapEntry->Obs.CurrentValue/*, Occlusion.CurrentValue*/);
	}
}

void AkOcclusionObstructionService::ClearOcclusionValues()
{
	ClearingOcclusionObstruction = false;

	for (auto& ListenerPack : ListenerInfoMap)
	{
		FAkListenerOcclusionObstructionPair& Pair = ListenerPack.Value;
		Pair.Occ.SetTarget(0.0f);
		Pair.Obs.SetTarget(0.0f);
		ClearingOcclusionObstruction |= !Pair.ReachedTarget();
	}
}

void AkOcclusionObstructionService::Tick(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, float DeltaTime, float OcclusionRefreshInterval)
{
	// Check Occlusion/Obstruction, if enabled
	if (OcclusionRefreshInterval > 0.0f || ClearingOcclusionObstruction)
	{
		RefreshObstructionOcclusion(in_Listeners, SourcePosition, Actor, RoomID, in_collisionChannel, DeltaTime, OcclusionRefreshInterval);
	}
	else if (OcclusionRefreshInterval != PreviousRefreshInterval)
	{
		// Reset the occlusion obstruction pairs so that the occlusion is correctly recalculated.
		for (auto& ListenerPack : ListenerInfoMap)
		{
			FAkListenerOcclusionObstructionPair& Pair = ListenerPack.Value;
			Pair.Reset();
		}
		if (OcclusionRefreshInterval <= 0.0f)
			ClearOcclusionValues();
	}
	PreviousRefreshInterval = OcclusionRefreshInterval;
}

void AkOcclusionObstructionService::UpdateObstructionOcclusion(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, float OcclusionRefreshInterval)
{
	if (OcclusionRefreshInterval > 0.f || ClearingOcclusionObstruction)
	{
		for (auto& Listener : in_Listeners)
		{
			auto& MapEntry = ListenerInfoMap.FindOrAdd(Listener->GetAkGameObjectID());
			MapEntry.Position = Listener->GetPosition();
		}
		CalculateObstructionOcclusionValues(in_Listeners, SourcePosition, Actor, RoomID, in_collisionChannel, false);
		for (auto& ListenerPair : ListenerInfoMap)
		{
			ListenerPair.Value.Obs.CurrentValue = ListenerPair.Value.Obs.TargetValue;
			ListenerPair.Value.Occ.CurrentValue = ListenerPair.Value.Occ.TargetValue;
		}
		SetObstructionOcclusion(in_Listeners, RoomID);
	}
}

