#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TutorialInfo.h"
#include "TutorialSequence.generated.h"

USTRUCT(BlueprintType)
struct FTutorialSequence : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TutorialName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTutorialInfo> TutorialSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CleanupMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString KnowledgeCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString KnowledgeUnlock;
    
    PHOENIX_API FTutorialSequence();
};

