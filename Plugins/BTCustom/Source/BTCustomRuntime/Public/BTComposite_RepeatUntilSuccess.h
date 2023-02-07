#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTComposite_RepeatUntilSuccess.generated.h"

UCLASS(Blueprintable)
class UBTComposite_RepeatUntilSuccess : public UBTCompositeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_leafNodeBBKey;
    
    UBTComposite_RepeatUntilSuccess();
};

