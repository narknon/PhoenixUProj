#pragma once
#include "CoreMinimal.h"
#include "MapDebugPaneItem.generated.h"

class UTextBlock;

USTRUCT(BlueprintType)
struct FMapDebugPaneItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* TextBlock;
    
    PHOENIX_API FMapDebugPaneItem();
};

