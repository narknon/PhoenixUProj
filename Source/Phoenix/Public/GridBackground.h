#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/CanvasPanel.h"
#include "GridBackground.generated.h"

UCLASS(Blueprintable)
class UGridBackground : public UCanvasPanel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor GridColor;
    
    UGridBackground();
    UFUNCTION(BlueprintCallable)
    void PopulateGrid(FVector2D GridSpacing, int32 Rows, int32 Columns);
    
};

