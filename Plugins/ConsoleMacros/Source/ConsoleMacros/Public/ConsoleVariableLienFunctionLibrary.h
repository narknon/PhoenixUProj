#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ConsoleVariableLienFunctionLibrary.generated.h"

class UConsoleVariableLienAsset;
class UObject;

UCLASS(Blueprintable)
class CONSOLEMACROS_API UConsoleVariableLienFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UConsoleVariableLienFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableRemoveLiens(UObject* LienHolder, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableRemoveLien(UObject* LienHolder, const FString& Variable, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableRemoveAssetLiens(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ConsoleVariableHasLien(UObject* LienHolder, const FString& Variable, bool& bHasALien);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ConsoleVariableHasAnyLiens(UObject* LienHolder, bool& bHasALien);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAssetLiensActivate(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess, bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAddStringLien(UObject* LienHolder, const FString& Variable, const FString& Value, bool& bSuccess, float Priority);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAddIntegerLien(UObject* LienHolder, const FString& Variable, int32 Value, bool& bSuccess, float Priority);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAddFloatLien(UObject* LienHolder, const FString& Variable, float Value, bool& bSuccess, float Priority);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAddDefaultLien(UObject* LienHolder, const FString& Variable, bool& bSuccess, float Priority);
    
    UFUNCTION(BlueprintCallable)
    static void ConsoleVariableAddAssetLiens(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess);
    
};

