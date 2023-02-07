#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SampleTextureToCurve.h"
#include "CurveFromTextureLibrary.generated.h"

class UCurveLinearColor;
class UTexture2D;

UCLASS(Blueprintable)
class CURVEHELPERS_API UCurveFromTextureLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCurveFromTextureLibrary();
    UFUNCTION(BlueprintCallable)
    static void TextureToLinearColorCurve(UTexture2D* Texture, FSampleTextureToCurve Settings, UCurveLinearColor* ColorCurve, bool& Worked);
    
};

