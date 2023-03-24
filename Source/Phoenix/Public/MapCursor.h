#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DecalActor.h"
#include "ECursorControlTypes.h"
#include "MapCursor.generated.h"

class AActor;
class APlayerController;
class ULocalPlayer;
class UMapBase;
class UMapHogsmeade;
class UMapHogwarts;
class UMapMovementComponent;
class UMapOverland;
class UMapScreenBase;
class UMapSubSystem;
class UMaterial;
class UMaterialInstanceDynamic;
class USceneComponent;
class UTexture2D;
class UUIManager;
class UWorld;

UCLASS(Blueprintable)
class AMapCursor : public ADecalActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeedMultiplierDungeon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeedMultiplierZoomFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeedMultiplierZoomFactorDungeon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldSnapCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFadeFromCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeDistanceFromCursorToStartFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFadeDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableMouseInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseSlop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SnapToIconLerpFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SnapToIconLerpFactorHogwarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalHorinzontalCollideAdjust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseEdgeMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShowMouseCursorTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalEdgeBoundTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalEdgeBoundBottom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorizontalEdgeBound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorMoveOnScroll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToggleInputLerpFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterial* CursorMaterial;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CursorTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapScreenBase* MapScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUIManager* UIManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapSubSystem* MapSubSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerController* PlayerController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapBase* MapBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapOverland* OverlandMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogsmeade* HogsmeadeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogwarts* HogwartsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMovementComponent* MapMoveComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocalPlayer* LocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* TraceWorld;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* HitActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LastHitActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* StaticHitComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* LastStaticHitComponent;
    
public:
    AMapCursor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleShowScreenPosition();
    
    UFUNCTION(BlueprintCallable)
    void ToggleShowMouseLocation();
    
    UFUNCTION(BlueprintCallable)
    void ToggleShowCursorLocation();
    
    UFUNCTION(BlueprintCallable)
    void ToggleShowCollisionActor();
    
    UFUNCTION(BlueprintCallable)
    void SetToMouse();
    
    UFUNCTION(BlueprintCallable)
    void SetToGamePad(bool doLerp, FVector lerpLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetScreenBounds(FVector4 BoundsArray);
    
    UFUNCTION(BlueprintCallable)
    void SetRightMouseButtonClicked(bool Clicked);
    
    UFUNCTION(BlueprintCallable)
    void SetCursorControl(TEnumAsByte<ECursorControlTypes::Type>& ControlType);
    
    UFUNCTION(BlueprintCallable)
    void SetCursorBounds(FVector4 BoundsArray);
    
    UFUNCTION(BlueprintCallable)
    void MouseSnapToPlayer();
    
    UFUNCTION(BlueprintCallable)
    FVector4 GetScreenBounds();
    
    UFUNCTION(BlueprintCallable)
    bool GetMouseActive();
    
    UFUNCTION(BlueprintCallable)
    bool GetLerpingToNewLocation();
    
    UFUNCTION(BlueprintCallable)
    bool GetGamePadActive();
    
    UFUNCTION(BlueprintCallable)
    FVector GetCursorTranslation();
    
    UFUNCTION(BlueprintCallable)
    FVector4 GetCursorBounds();
    
    UFUNCTION(BlueprintCallable)
    void GamepadSnapToPlayer();
    
};

