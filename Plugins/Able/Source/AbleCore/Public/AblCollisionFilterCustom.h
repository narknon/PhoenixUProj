#pragma once
#include "CoreMinimal.h"
#include "AblCollisionFilter.h"
#include "AblCollisionFilterCustom.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterCustom : public UAblCollisionFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_UseAsync;
    
public:
    UAblCollisionFilterCustom();
};

