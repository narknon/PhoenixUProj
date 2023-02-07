#pragma once
#include "CoreMinimal.h"
#include "AblCollisionFilter.h"
#include "AblCollisionFilterMaxResults.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterMaxResults : public UAblCollisionFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_MaxEntities;
    
public:
    UAblCollisionFilterMaxResults();
};

