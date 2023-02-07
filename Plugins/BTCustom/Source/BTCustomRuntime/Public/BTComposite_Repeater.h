#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTComposite_Repeater.generated.h"

UCLASS(Blueprintable)
class UBTComposite_Repeater : public UBTCompositeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_leafNodeBBKey;
    
    UBTComposite_Repeater();
};

