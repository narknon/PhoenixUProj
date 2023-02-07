#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_DistanceProvider.h"
#include "ConversationPreset_DistanceProvider_Single.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_DistanceProvider_Single : public UConversationPreset_DistanceProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UConversationPreset_DistanceProvider_Single();
};

