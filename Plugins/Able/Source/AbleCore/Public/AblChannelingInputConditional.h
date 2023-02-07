#pragma once
#include "CoreMinimal.h"
#include "AblChannelingBase.h"
#include "AblChannelingInputConditional.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblChannelingInputConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> m_InputActions;
    
public:
    UAblChannelingInputConditional();
};

