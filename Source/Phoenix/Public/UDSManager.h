#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UDSManager.generated.h"

class UUDSActivityManager;
class UUDSEventQueuer;
class UUDSFieldGuideManager;
class UUDSIntentManager;
class UUDSLocationManager;
class UUDSMechanicManager;
class UUDSStatManager;

UCLASS(Blueprintable)
class UUDSManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSStatManager* UDSStatManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSIntentManager* UDSIntentManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSMechanicManager* UDSMechanicManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSActivityManager* UDSActivityManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSFieldGuideManager* UDSFieldGuideManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSLocationManager* UDSLocationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSEventQueuer* UDSEventQueuer;
    
public:
    UUDSManager();
private:
    UFUNCTION(BlueprintCallable)
    void SyncUDSWithGameData();
    
    UFUNCTION(BlueprintCallable)
    void ResetPlayerStateIfCurrentSaveDeleted(int32 DeletedCharacterId);
    
    UFUNCTION(BlueprintCallable)
    void LoadPlayerStateFromSaveFile();
    
    UFUNCTION(BlueprintCallable)
    void InjectPlayerStateIntoSaveFile();
    
};

