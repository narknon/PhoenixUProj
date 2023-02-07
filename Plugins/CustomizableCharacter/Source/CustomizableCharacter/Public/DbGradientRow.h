#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbGradientRow.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FDbGradientRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture> Texture;
    
    CUSTOMIZABLECHARACTER_API FDbGradientRow();
};

