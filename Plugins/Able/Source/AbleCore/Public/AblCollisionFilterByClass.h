#pragma once
#include "CoreMinimal.h"
#include "AblCollisionFilter.h"
#include "AblCollisionFilterByClass.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterByClass : public UAblCollisionFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* m_Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Negate;
    
public:
    UAblCollisionFilterByClass();
};

