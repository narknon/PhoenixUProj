#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "AblNpcSpawnMunitionTask.generated.h"

class AMunitionType_Base;
class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcSpawnMunitionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseReactionInstigatorAsMunitionInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UAblNpcSpawnMunitionTask();
};

