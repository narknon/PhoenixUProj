#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DbEditorButtonWidget.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "FastTravelLocation.generated.h"

UCLASS(Blueprintable)
class AFastTravelLocation : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocationIdName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo RegionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSaveLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HUDOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbEditorButtonWidget AddButton;
    
    AFastTravelLocation();
    UFUNCTION(BlueprintCallable)
    void Unlock();
    
    UFUNCTION(BlueprintCallable)
    void SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable)
    void Lock();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetInteractLocationBP(const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    bool GetAvailable();
    
    UFUNCTION(BlueprintCallable)
    void AdjustCogTargetPoint(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void AdjustBeaconWorldLocation(const FString& Name, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Activate(bool ACTIVE);
    
};

