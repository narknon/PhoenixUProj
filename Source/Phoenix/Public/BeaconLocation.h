#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DbDoubleColumnInfo.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TargetPoint.h"
#include "EBeaconDisplayPriority.h"
#include "EBeaconType.h"
#include "BeaconLocation.generated.h"

class AActor;

UCLASS(Blueprintable)
class ABeaconLocation : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HUDMarkerOffset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbDoubleColumnInfo ItemInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BeaconID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BeaconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeaconableObjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaconType BeaconType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo BeaconIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DescriptionShort;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ActivationDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 EnterExitDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaconDisplayPriority BeaconPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMakeDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideWhenInactive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartInactive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSaveLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawDebug;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ParentObject;
    
public:
    ABeaconLocation();
    UFUNCTION(BlueprintCallable)
    void SetStartInactive(bool inStartInactive);
    
    UFUNCTION(BlueprintCallable)
    void SetShowInWorld(bool inShowInWorld);
    
    UFUNCTION(BlueprintCallable)
    void SetParentObject(AActor* inParentObject);
    
    UFUNCTION(BlueprintCallable)
    void SetMakeDynamic(bool inMakeDynamic);
    
    UFUNCTION(BlueprintCallable)
    void SetIsSaveLocation(bool isSaveLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetHudIconSuppressed(bool bInHudIconSuppressed);
    
    UFUNCTION(BlueprintCallable)
    void SetHideWhenInactive(bool inHideWhenInactive);
    
    UFUNCTION(BlueprintCallable)
    void SetEnterExitDistance(int32 InDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetDescriptionShort(const FString& inNewShortDesc);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconType(EBeaconType inBeaconType);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconPriority(EBeaconDisplayPriority InPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconName(const FString& inNewBeaconName);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconDebug(bool inDoDebug);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconableObjectID(FName inNewID);
    
    UFUNCTION(BlueprintCallable)
    void SetActivationDistance(int32 InDistance);
    
    UFUNCTION(BlueprintCallable)
    bool GetStartInactive();
    
    UFUNCTION(BlueprintCallable)
    bool GetShowInWorld();
    
    UFUNCTION(BlueprintCallable)
    bool GetMakeDynamic();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsSaveLocation();
    
    UFUNCTION(BlueprintCallable)
    bool GetHideWhenInactive();
    
    UFUNCTION(BlueprintCallable)
    int32 GetEnterExitDistance();
    
    UFUNCTION(BlueprintCallable)
    bool GetDrawDebug();
    
    UFUNCTION(BlueprintCallable)
    FString GetDescriptionShort();
    
    UFUNCTION(BlueprintCallable)
    EBeaconType GetBeaconType();
    
    UFUNCTION(BlueprintCallable)
    EBeaconDisplayPriority GetBeaconPriority();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconName();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconID();
    
    UFUNCTION(BlueprintCallable)
    FDbSingleColumnInfo GetBeaconIcon();
    
    UFUNCTION(BlueprintCallable)
    int32 GetBeaconHandle();
    
    UFUNCTION(BlueprintCallable)
    FName GetBeaconableObjectID();
    
    UFUNCTION(BlueprintCallable)
    int32 GetActivationDistance();
    
};

