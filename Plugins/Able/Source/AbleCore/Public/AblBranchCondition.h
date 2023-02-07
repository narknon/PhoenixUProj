#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblBranchCondition.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblBranchCondition : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Negate;
    
public:
    UAblBranchCondition();
};

