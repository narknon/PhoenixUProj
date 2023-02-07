#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbTextureRow.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FDbTextureRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MeshName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture> Texture;
    
    CUSTOMIZABLECHARACTER_API FDbTextureRow();
};

