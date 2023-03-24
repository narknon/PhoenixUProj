#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EHoverDroneControlMode.h"
#include "HoverDroneConfigStruct.h"
#include "HoverDroneControlModeChangedDelegate.h"
#include "HoverDroneToggleMiniMapDelegate.h"
#include "Templates/SubclassOf.h"
#include "HoverDroneController.generated.h"

class APawn;
class APhoenixHoverDronePawn;
class APlayerController;
class UInputComponent;

UCLASS(Blueprintable)
class HOVERDRONE_API AHoverDroneController : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoverDroneControlModeChanged OnControlModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoverDroneToggleMiniMap OnToggleMiniMap;
    
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APawn> ControlModePawnClass[3];
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* m_MinimapWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* m_pFollowActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoverDroneConfigStruct MyStruct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* m_pInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerController* m_pPlayerController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpToBookmarkCameraFadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpToBookmarkCameraHoldBlackTime;
    
public:
    AHoverDroneController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleHUD();
    
    UFUNCTION(BlueprintCallable)
    void StartHoverDroneFromSystemMenu();
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerBounds(FVector BoundsMin, FVector BoundsMax);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPlayerBounds(FVector& Max, FVector& Min) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPawnAltitude() const;
    
    UFUNCTION(BlueprintCallable)
    APhoenixHoverDronePawn* GetDronePawn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetControlModeString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EHoverDroneControlMode::Type> GetControlMode() const;
    
};

