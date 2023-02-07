#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "EAttachCameraBillBoardType.h"
#include "EAttachCameraType.h"
#include "AttachCameraComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UAttachCameraComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAttachCameraType AttachType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAttachCameraBillBoardType BillBoardType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LocalRotator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCopyToRootComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableInEditor;
    
    UAttachCameraComponent();
    UFUNCTION(BlueprintCallable)
    void SetupCopyToRootComponent(bool copyToRootComponent);
    
    UFUNCTION(BlueprintCallable)
    void ResetChildRotations();
    
    UFUNCTION(BlueprintCallable)
    void ResetChildLocations();
    
    UFUNCTION(BlueprintCallable)
    void ResetAllChildren();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCameraRotation(FRotator& Rotation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCameraLocation(FVector& Eye) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCamera(FVector& Eye, FRotator& Orientation) const;
    
};

