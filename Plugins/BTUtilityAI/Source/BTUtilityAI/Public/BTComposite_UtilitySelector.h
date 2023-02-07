#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "EUtilitySelectionMethod.h"
#include "UtilityScoreProvider.h"
#include "BTComposite_UtilitySelector.generated.h"

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTComposite_UtilitySelector : public UBTCompositeNode, public IUtilityScoreProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUtilitySelectionMethod SelectionMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreRank;
    
    UBTComposite_UtilitySelector();
    
    // Fix for true pure virtual functions not being implemented
};

