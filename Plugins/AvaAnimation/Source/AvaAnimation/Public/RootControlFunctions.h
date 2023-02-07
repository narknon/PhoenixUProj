#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RootControlFunctions.generated.h"

class AActor;

UCLASS(Blueprintable)
class AVAANIMATION_API URootControlFunctions : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URootControlFunctions();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AdjustWorldSpaceTransform(AActor* Actor, const FVector& TranslationOffset, const FRotator& RotationOffset);
    
};

