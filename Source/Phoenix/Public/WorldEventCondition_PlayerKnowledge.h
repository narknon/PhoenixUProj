#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeLevel.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_PlayerKnowledge.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_PlayerKnowledge : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ObjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FactColumnID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EKnowledgeLevel MinimumKnowledgeRequired;
    
    UWorldEventCondition_PlayerKnowledge();
};

