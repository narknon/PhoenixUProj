#include "PortraitPaintingActor.h"
#include "Components/BillboardComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

class AActor;
class UScheduledEntity;
class UTexture;

void APortraitPaintingActor::SetPaintingFrameMask(UTexture* PaintingFrameMask) {
}

void APortraitPaintingActor::SetPaintingBackground(UTexture* PaintingBackground) {
}

void APortraitPaintingActor::OnFleshLoaded(AActor* Actor, UScheduledEntity* ScheduledEntity) {
}

void APortraitPaintingActor::OnCharacterLoadComplete(AActor* Actor) {
}

APortraitPaintingActor::APortraitPaintingActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PortraitActorRange = 1000.00f;
    this->CameraFarPlane = 1000.00f;
    this->MainPortraitSwapType = EMaterialPermuterLoadingBundleAndSwapType::Hard;
    this->PaintingPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaintingPlane"));
    this->Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
    this->CustomLighting = CreateDefaultSubobject<USceneComponent>(TEXT("CustomLighting"));
    this->Light0 = CreateDefaultSubobject<UBillboardComponent>(TEXT("Light 1"));
    this->Light1 = CreateDefaultSubobject<UBillboardComponent>(TEXT("Light 2"));
    this->Light2 = CreateDefaultSubobject<UBillboardComponent>(TEXT("Light 3"));
    this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    this->BackgroundTexture = NULL;
    this->FrameMaskTexture = NULL;
    this->CanvasNormalTexture = NULL;
    this->CanvasRoughnessTexture = NULL;
    this->NormalIntensity = 1.00f;
    this->TextureTiling = 1.00f;
    this->FlattenPercent = 1.00f;
    this->RotationOffsetInDegrees = 0.00f;
    this->SkinNormalSoftness = 0.40f;
    this->SkinSpecularScale = 0.80f;
    this->SkinScatterScale = 2.50f;
    this->BottomFadeHeight = 60.00f;
    this->BottomFadeStrength = 0.40f;
    this->LightingPointIntensity_0 = 1.50f;
    this->LightingPointIntensity_1 = 0.80f;
    this->LightingPointIntensity_2 = 3.00f;
    this->MainSwap = NULL;
    this->bReadyForEntities = false;
    this->PaintingMaterial = NULL;
}

