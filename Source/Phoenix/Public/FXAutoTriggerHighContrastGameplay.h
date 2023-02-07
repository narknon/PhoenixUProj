#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EHighContrastGameplayMarkup.h"
#include "EHighContrastGameplayNPCHint.h"
#include "FXAutoTriggerHighContrastGameplay.generated.h"

class AActor;
class UMeshComponent;
class UObject;

UCLASS(Blueprintable)
class UFXAutoTriggerHighContrastGameplay : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFXAutoTriggerHighContrastGameplay();
    UFUNCTION(BlueprintCallable)
    static void RemoveNPCHighContrastGameplayHints(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsHighContrastGameplay(UObject* WorldContextObject, bool& bHighContrastGameplay);
    
    UFUNCTION(BlueprintCallable)
    static void HighContrastGameplayMarkupMeshImmediateVeryDangerous(UMeshComponent* MeshComponent, EHighContrastGameplayMarkup Markup);
    
    UFUNCTION(BlueprintCallable)
    static void HighContrastGameplayMarkupActorImmediateVeryDangerous(AActor* Actor, EHighContrastGameplayMarkup Markup, bool bIncludeChildren);
    
    UFUNCTION(BlueprintCallable)
    static void GetNPCHighContrastGameplayHint(AActor* Actor, EHighContrastGameplayNPCHint& Hint, bool& bHasHint);
    
    UFUNCTION(BlueprintCallable)
    static void AddNPCHighContrastGameplayHint(AActor* Actor, EHighContrastGameplayNPCHint Hint);
    
};

