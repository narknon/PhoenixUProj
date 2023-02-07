#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "RPGUIInfo.h"
#include "RPGAbilityBase.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class PHOENIX_API URPGAbilityBase : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime StartInGameTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime EndInGameTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RemainingLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OwnerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OwnerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGUIInfo UIIconInfo;
    
public:
    URPGAbilityBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReequipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipped();
    
};

