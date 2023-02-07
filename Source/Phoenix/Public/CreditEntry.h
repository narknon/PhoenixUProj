#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ECreditEntryType.h"
#include "CreditEntry.generated.h"

USTRUCT(BlueprintType)
struct FCreditEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreditEntryType EntryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Translated;
    
    PHOENIX_API FCreditEntry();
};

