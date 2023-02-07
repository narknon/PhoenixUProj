#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConsoleVariableWatcher.generated.h"

class UObject;
class UWatchedConsoleVariableBool;
class UWatchedConsoleVariableFloat;
class UWatchedConsoleVariableInt;

UCLASS(Blueprintable, NotPlaceable, Transient)
class CONSOLEMACROS_API AConsoleVariableWatcher : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWatchedConsoleVariableBool*> BoolVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWatchedConsoleVariableFloat*> FloatVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWatchedConsoleVariableInt*> IntVariables;
    
    AConsoleVariableWatcher();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void WatchIntConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableInt*& Variable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void WatchFloatConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableFloat*& Variable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void WatchBoolConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableBool*& Variable);
    
    UFUNCTION(BlueprintCallable)
    static void SetConsoleVariableAsInt(const FString& ConsoleVariable, int32 Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable)
    static void SetConsoleVariableAsFloat(const FString& ConsoleVariable, float Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable)
    static void SetConsoleVariableAsBool(const FString& ConsoleVariable, bool Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetConsoleVariableAsInt(const FString& ConsoleVariable, int32& Value, bool& bExists, int32 DefaultValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetConsoleVariableAsFloat(const FString& ConsoleVariable, float& Value, bool& bExists, float DefaultValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetConsoleVariableAsBool(const FString& ConsoleVariable, bool& bValue, bool& bExists, bool bDefaultValue);
    
    UFUNCTION(BlueprintCallable)
    static void CreateConsoleVariableAsInt(const FString& ConsoleVariable, int32 DefaultValue, const FString& Help, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void CreateConsoleVariableAsFloat(const FString& ConsoleVariable, float DefaultValue, const FString& Help, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void CreateConsoleVariableAsBool(const FString& ConsoleVariable, bool DefaultValue, const FString& Help, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ConsoleVariableExists(const FString& ConsoleVariable, bool& bExists);
    
};

