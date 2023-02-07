#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WordRow.generated.h"

USTRUCT(BlueprintType)
struct FWordRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Locale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysCheck;
    
    UTILITIESRUNTIME_API FWordRow();
};

