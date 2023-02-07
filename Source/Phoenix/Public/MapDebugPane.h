#pragma once
#include "CoreMinimal.h"
#include "MapDebugPaneItem.h"
#include "MapDebugPane.generated.h"

class UCanvasPanel;

USTRUCT(BlueprintType)
struct FMapDebugPane {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CanvasPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapDebugPaneItem> TextBlocks;
    
    PHOENIX_API FMapDebugPane();
};

