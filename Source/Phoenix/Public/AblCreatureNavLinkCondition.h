#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ECreatureNavLinkType.h"
#include "AblCreatureNavLinkCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCreatureNavLinkCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureNavLinkType LinkType;
    
public:
    UAblCreatureNavLinkCondition();
};

