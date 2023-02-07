#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EEnemyBuffTypeEnum.h"
#include "EnemyBuff_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemyBuff_Interface : public UInterface {
    GENERATED_BODY()
};

class IEnemyBuff_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool UpdateBuffEmitterLocationAndRotFx(FVector Location, FRotator Rotation, EEnemyBuffTypeEnum BuffType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DestroyBuffEmitterFx(EEnemyBuffTypeEnum BuffType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DeactivateBuffEmitterFx(EEnemyBuffTypeEnum BuffType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CreateBuffEmitterFx(EEnemyBuffTypeEnum BuffType, FVector Location);
    
};

