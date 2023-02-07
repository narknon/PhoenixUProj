#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UStreamlineDLSSGMode.h"
#include "UStreamlineDLSSGSupport.h"
#include "StreamlineLibraryDLSSG.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UStreamlineLibraryDLSSG : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStreamlineLibraryDLSSG();
    UFUNCTION(BlueprintCallable)
    static void SetDLSSGMode(UStreamlineDLSSGMode DLSSGMode);
    
    UFUNCTION(BlueprintCallable)
    static void SetDLSSGFrames(int32 Frames);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineDLSSGSupport QueryDLSSGSupport();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDLSSGSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDLSSGModeSupported(UStreamlineDLSSGMode DLSSGMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UStreamlineDLSSGMode> GetSupportedDLSSGModes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetDLSSGSupportedFramesRange(int32& MinFrames, int32& MaxFrames);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineDLSSGMode GetDLSSGMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetDLSSGMinimumDriverVersion(int32& MinDriverVersionMajor, int32& MinDriverVersionMinor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetDLSSGFrames();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStreamlineDLSSGMode GetDefaultDLSSGMode();
    
};

