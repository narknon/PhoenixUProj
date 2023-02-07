#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblChannelingBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblChannelingBase : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Negate;
    
public:
    UAblChannelingBase();
};

