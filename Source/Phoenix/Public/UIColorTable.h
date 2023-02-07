#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "Engine/DataTable.h"
#include "Rendering/RenderingCommon.h"
#include "UIColorTable.generated.h"

UCLASS(Blueprintable)
class UUIColorTable : public UObject {
    GENERATED_BODY()
public:
    UUIColorTable();
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetColorByTag(FName pColorTag);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetColorByRowHandleBP(FDataTableRowHandle pRowHandle);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetColorByRowHandle(FDataTableRowHandle& pRowHandle);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor CreateColorBlindColor(EColorVisionDeficiency pColorType, FLinearColor pColor, int32 bCorrectDeficiency, int32 bSimulateCorrectionWithDeficiency, int32 Severity);
    
};

