#pragma once
#include "CoreMinimal.h"
#include "KnowledgeInfo.generated.h"

USTRUCT(BlueprintType)
struct EDITORCUSTOMIZATIONHELPER_API FKnowledgeInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> AllowedObjectGroupList;
    
    FKnowledgeInfo();
};

