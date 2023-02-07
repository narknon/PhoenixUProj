#pragma once
#include "CoreMinimal.h"
#include "StoryNode_Custom.h"
#include "StoryNode_HermesMessage.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UStoryNode_HermesMessage : public UStoryNode_Custom {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MessageName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEventCanTriggerMultipleTimes;
    
    UStoryNode_HermesMessage();
};

