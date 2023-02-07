#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AvaAudioLowBPLibrary.generated.h"

UCLASS(Blueprintable)
class AVAAUDIOLOW_API UAvaAudioLowBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAvaAudioLowBPLibrary();
    UFUNCTION(BlueprintCallable)
    static float AvaAudioLowSampleFunction(float Param);
    
};

