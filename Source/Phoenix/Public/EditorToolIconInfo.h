#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EditorToolIconInfo.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FEditorToolIconInfo : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UObject> ClassUsedBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    PHOENIX_API FEditorToolIconInfo();
};

