#pragma once
#include "CoreMinimal.h"
#include "KnowledgeInfo.h"
#include "EKnowledgeAction.h"
#include "InvestigatableComponent.h"
#include "InvestigatableKnowledge.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInvestigatableKnowledge : public UInvestigatableComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKnowledgeInfo DbKnowledgeInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SecretFactLockNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EKnowledgeAction> KnowledgeActionOverride;
    
    UInvestigatableKnowledge();
};

