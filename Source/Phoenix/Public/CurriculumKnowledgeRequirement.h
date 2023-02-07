#pragma once
#include "CoreMinimal.h"
#include "CurriculumKnowledgeRequirement.generated.h"

USTRUCT(BlueprintType)
struct FCurriculumKnowledgeRequirement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString KnowledgeCardName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentLevel;
    
    PHOENIX_API FCurriculumKnowledgeRequirement();
};

