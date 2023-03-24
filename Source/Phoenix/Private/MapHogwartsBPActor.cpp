#include "MapHogwartsBPActor.h"

class AMapLocationActor;
class UMapHogwarts;
class UMapLocation;
class UMapMarkupComponent;
class UScheduledEntity;

void AMapHogwartsBPActor::SetStaticMapTarget(FVector Target) {
}

void AMapHogwartsBPActor::SetNextState(EMap3DState NewState) {
}

void AMapHogwartsBPActor::SetDynamicMapTarget(UScheduledEntity* Target) {
}

void AMapHogwartsBPActor::PushLocationListToScreen(const TArray<FString> InLocationList, int32 InStartIndex) {
}

void AMapHogwartsBPActor::PushLocaitonNameToScreen(const FString& LocationName) {
}






























void AMapHogwartsBPActor::GiveMeHelp() {
}

EMap3DState AMapHogwartsBPActor::GetState() {
    return EMap3DState::IDLE;
}

FString AMapHogwartsBPActor::GetRoomStairFloorString(UMapMarkupComponent* MapLocation, UMapMarkupComponent* StairLocation, UMapLocation* FloorLocation, UMapLocation* PrimaryrLocation, bool IsOnlyPrimaryLocation) {
    return TEXT("");
}

bool AMapHogwartsBPActor::GetIsActive() {
    return false;
}

UMapHogwarts* AMapHogwartsBPActor::GetHogwartsMap() {
    return NULL;
}

AMapLocationActor* AMapHogwartsBPActor::FindLocationActorThatContainsPoint(FVector Point) {
    return NULL;
}

AMapLocationActor* AMapHogwartsBPActor::FindLocationActorBelowPoint(FVector Point) {
    return NULL;
}

void AMapHogwartsBPActor::DoUp() {
}

void AMapHogwartsBPActor::DoSelect() {
}

void AMapHogwartsBPActor::DoDown() {
}

void AMapHogwartsBPActor::DoBack() {
}

void AMapHogwartsBPActor::ClearMapTarget() {
}

AMapHogwartsBPActor::AMapHogwartsBPActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PathMaterial = NULL;
    this->PostProcessMaterial = NULL;
    this->PostProcessMaterialInstance = NULL;
    this->TestLocation = NULL;
    this->HasTarget = false;
    this->CursorScale = 20.00f;
    this->CursorScaleFactor = -30.00f;
    this->CursorSnapDistance = 8000.00f;
    this->IsMapTargetScheduledEntity = false;
    this->MapTargetScheduledEntity = NULL;
    this->IsMapTargetWorldLocation = false;
    this->ShowFloors = false;
    this->UseNavPath = false;
    this->UpdatePathOnPrimaryLocationChange = false;
    this->bUsePointsOfInterest = false;
    this->MapData = NULL;
    this->FloorData = NULL;
    this->StairData = NULL;
    this->PlayerMarkerActor = NULL;
    this->FocusPointActor = NULL;
    this->PathEndActor = NULL;
    this->IsolationMeshComponent = NULL;
    this->UseZoomMaterailForPath = false;
    this->UVDistanceMul = 1.00f;
    this->UseComplexCollision = false;
    this->CameraParametersBirdsEye = NULL;
    this->DefaultStartComponent = NULL;
    this->DebugStairVolumeMaterial = NULL;
    this->DebugRoomVolumeMaterial = NULL;
    this->DebugFloorVolumeMaterial = NULL;
    this->TranslateSpeed = 10000.00f;
    this->NextPathPointActor = NULL;
    this->TargetName = TEXT("None");
    this->LastMapLocation = NULL;
    this->NavMeshLevel = NULL;
}

