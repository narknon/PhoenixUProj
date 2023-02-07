#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventSymbol.h"
#include "TimeRigNamedSymbol.generated.h"

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigNamedSymbol : public FTimeRigEventSymbol {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FTimeRigNamedSymbol();
};

