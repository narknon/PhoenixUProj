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
AkOcclusionObstructionService.h:
=============================================================================*/

#pragma once

#include "AkInclude.h"
#include "AkAudioDevice.h"
#include "WorldCollision.h"
#include "HAL/ThreadSafeBool.h"

#define NUM_BOUNDING_BOX_TRACE_POINTS 12
class UAkComponent;
class AActor;
class AAkAcousticPortal;

struct FAkListenerOcclusionObstruction
{
	float CurrentValue;
	float TargetValue;
	float Rate;

	FAkListenerOcclusionObstruction(float in_TargetValue = 0.0f, float in_CurrentValue = 0.0f);

	void SetTarget(float in_TargetValue);
	bool ReachedTarget();
	bool Update(float DeltaTime);
};

struct FAkListenerOcclusionObstructionPair
{
	FAkListenerOcclusionObstructionPair();

	FAkListenerOcclusionObstruction Occ;
	FAkListenerOcclusionObstruction Obs;
	FVector Position;

	bool Update(float DeltaTime);

	bool ReachedTarget();

	/** Trace a ray from a source position to a bounding box point asynchronously */
	void AsyncTraceFromSource(const FVector& SourcePosition, const FVector& EndPosition, int BoundingBoxPointIndex, ECollisionChannel CollisionChannel, UWorld* World, const FCollisionQueryParams& CollisionParams);
	/** Trace a ray from a listener position to a bounding box point asynchronously */
	void AsyncTraceFromListener(const FVector& ListenerPosition, const FVector& EndPosition, int BoundingBoxPointIndex, ECollisionChannel CollisionChannel, UWorld* World, const FCollisionQueryParams& CollisionParams);

	/** Get the total number of listener OR source collisions. */
	int GetCollisionCount();

	void Reset();


	/** Iterate through all trace handles and handle the results if ready */
	void CheckTraceResults(UWorld* World);


private:
	/** Used to check when obstruction and occlusion targets need to be updated (when GetCollisionCount() != CurrentCollisionCount) */
	int CurrentCollisionCount = 0;
	TArray<FTraceHandle> SourceTraceHandles;
	TArray<FTraceHandle> ListenerTraceHandles;

	/** Iterate through all listener trace handles and handle the trace results if ready */
	void CheckListenerTraceHandles(UWorld* World);
	/** Iterate through all source trace handles and handle the trace results if ready */
	void CheckSourceTraceHandles(UWorld* World);

	TArray<FThreadSafeBool> SourceRayCollisions;
	TArray<FThreadSafeBool> ListenerRayCollisions;
};

class AkOcclusionObstructionService
{
public:
	void Tick(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, float DeltaTime, float OcclusionRefreshInterval);

	/**
	 * Calculates updated occlusion and obstruction values synchronously and then sends them to the Wwise engine.
	 */
	void UpdateObstructionOcclusion(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, float OcclusionRefreshInterval);

	void ClearOcclusionValues();

	virtual void SetOcclusionObstruction(AkGameObjectID ListenerID, float Value) = 0;

	virtual ~AkOcclusionObstructionService() {}

protected:
	void _Init(UWorld* in_world, float in_refreshInterval);

private:
	/**
	 * Fades active occlusions towards targets, sends updated values to the Wwise engine, then calculates refreshed occlusion and obstruction values asynchronously. 
	 */
	void RefreshObstructionOcclusion(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, const float DeltaTime, float OcclusionRefreshInterval);
	/**
	 * Loops through in_Listeners and sends the obstruction occlusion values on each to the Wwise engine.
	 */
	void SetObstructionOcclusion(const UAkComponentSet& in_Listeners, AkRoomID RoomID);
	/**
	* Calculates updated occlusion and obstruction values.
	*/
	void CalculateObstructionOcclusionValues(const UAkComponentSet& in_Listeners, const FVector& SourcePosition, const AActor* Actor, AkRoomID RoomID, ECollisionChannel in_collisionChannel, bool bAsync = true);


	/** Last time occlusion was refreshed */
	float LastObstructionOcclusionRefresh = -1;
	float PreviousRefreshInterval = -1.0f;

	bool ClearingOcclusionObstruction = false;

	typedef AkGameObjectIdKeyFuncs<FAkListenerOcclusionObstructionPair, false> ListenerOccObsPairGameObjectIDKeyFuncs;
	TMap<AkGameObjectID, FAkListenerOcclusionObstructionPair, FDefaultSetAllocator, ListenerOccObsPairGameObjectIDKeyFuncs> ListenerInfoMap;
};