#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EAblAbilityStartResult.h"
#include "Templates/SubclassOf.h"
#include "AblAbilityBlueprintLibrary.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityComponent;
class UAblAbilityContext;
class UAblCustomTaskScratchPad;

UCLASS(Blueprintable)
class ABLECORE_API UAblAbilityBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAblAbilityBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static bool SetDrawCollisionQueries(bool Enable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSuccessfulStartResult(EAblAbilityStartResult Result);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDrawCollisionQueries();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAblAbility* GetAbilityObjectFromClass(UClass* Class);
    
    UFUNCTION(BlueprintCallable)
    static UAblCustomTaskScratchPad* CreateCustomScratchPad(UAblAbilityContext* Context, TSubclassOf<UAblCustomTaskScratchPad> ScratchPadClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAblAbilityContext* CreateAbilityContext(const UAblAbility* Ability, UAblAbilityComponent* AbilityComponent, AActor* Owner, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    static EAblAbilityStartResult ActivateAbility(UAblAbilityContext* Context);
    
};

