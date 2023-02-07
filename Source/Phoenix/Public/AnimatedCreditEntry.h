#pragma once
#include "CoreMinimal.h"
#include "AnimatedCreditEntry.generated.h"

class UPhoenixCreditEntryWidget;

USTRUCT(BlueprintType)
struct FAnimatedCreditEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixCreditEntryWidget* EntryWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EntryStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EntryEndTime;
    
    PHOENIX_API FAnimatedCreditEntry();
};

