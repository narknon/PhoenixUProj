#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblAbilityTaskRealm.h"
#include "AblCollisionQueryTask.generated.h"

class UAblCollisionFilter;
class UAblCollisionShape;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionQueryTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_fireEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblCollisionShape* m_QueryShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblCollisionFilter*> m_Filters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_CopyResultsToContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_AllowDuplicateEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblAbilityTaskRealm m_TaskRealm;
    
public:
    UAblCollisionQueryTask();
};

