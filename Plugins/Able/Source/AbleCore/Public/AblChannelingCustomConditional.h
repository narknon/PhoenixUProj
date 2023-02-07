#pragma once
#include "CoreMinimal.h"
#include "AblChannelingBase.h"
#include "AblChannelingCustomConditional.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblChannelingCustomConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_EventName;
    
public:
    UAblChannelingCustomConditional();
};

