#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkWaapiUri.h"
#include "AkWaapiUriConv.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkWaapiUriConv : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAkWaapiUriConv();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText Conv_FAkWaapiUriToText(const FAkWaapiUri& INAkWaapiUri);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString Conv_FAkWaapiUriToString(const FAkWaapiUri& INAkWaapiUri);
    
};

