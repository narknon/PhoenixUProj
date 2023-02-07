#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkPropertyToControl.h"
#include "AkItemPropertiesConv.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkItemPropertiesConv : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAkItemPropertiesConv();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText Conv_FAkPropertyToControlToText(const FAkPropertyToControl& INAkPropertyToControl);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString Conv_FAkPropertyToControlToString(const FAkPropertyToControl& INAkPropertyToControl);
    
};

