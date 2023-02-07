#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EConversationPreset_ProximityType.h"
#include "ConversationPreset_DistanceProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UConversationPreset_DistanceProvider : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationPreset_ProximityType Proximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Force;
    
    UConversationPreset_DistanceProvider();
};

