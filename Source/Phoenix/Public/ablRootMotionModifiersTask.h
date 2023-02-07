#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablRootMotionModifiersTask.generated.h"

class UAblTaskCondition;
class URootMotionModifierProperties;

UCLASS(Blueprintable, EditInlineNew)
class UablRootMotionModifiersTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URootMotionModifierProperties*> m_RootMotionModifierPropertiesArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UablRootMotionModifiersTask();
};

