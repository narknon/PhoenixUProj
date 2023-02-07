#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EGameLogicEditorPanel.h"
#include "EGameLogicElementSize.h"
#include "GameLogicRealmSettings.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicExpression.h"
#include "Global_GameLogicPropositional_Bitfield.h"
#include "Global_GameLogicPropositional_Enum.h"
#include "Global_GameLogicPropositional_Float.h"
#include "Global_GameLogicPropositional_Int32.h"
#include "Global_GameLogicPropositional_String.h"
#include "Global_GameLogicVar_Bitfield.h"
#include "Global_GameLogicVar_Bool.h"
#include "Global_GameLogicVar_Enum.h"
#include "Global_GameLogicVar_Float.h"
#include "Global_GameLogicVar_Int32.h"
#include "Global_GameLogicVar_String.h"
#include "Global_GameLogicVar_Timer.h"
#include "GameLogicGameSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=GameLogic)
class GAMELOGICRUNTIME_API UGameLogicGameSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Realms;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameLogicRealmSettings> RealmSettings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Bool> BoolVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Int32> Int32Vars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Float> FloatVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Timer> TimerVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Enum> EnumVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_Bitfield> BitfieldVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicVar_String> StringVars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicPropositional_Int32> PropInt32s;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicPropositional_Float> PropFloats;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicPropositional_Enum> PropEnums;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicPropositional_Bitfield> PropBitfields;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicPropositional_String> PropStrings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobal_GameLogicExpression> Expressions;
    
    UGameLogicGameSettings();
    UFUNCTION(BlueprintCallable)
    static void SetElementSizeByPanelAndRealm(EGameLogicElementSize InSize, EGameLogicEditorPanel ElementType, FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveElementByIndex(EGameLogicEditorPanel ElementType, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static void MoveElementByIndex(EGameLogicEditorPanel ElementType, int32 Index, int32 IndexDelta, bool bUseRealm, const FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsValidElementName(const FName& InName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsUniqueElementName(const FName& InName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetIndexFromElement(EGameLogicEditorPanel ElementType, const FGlobal_GameLogicElement& InElement, bool bUseRealm, const FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static EGameLogicElementSize GetElementSizeByPanelAndRealm(EGameLogicEditorPanel ElementType, FName RealmName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetElementNames(TArray<FName>& ElementNames) const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCountFromElement(EGameLogicEditorPanel ElementType, bool bUseRealm, const FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static bool ElementPanelHasReferences(EGameLogicEditorPanel ElementType, FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static bool ElementHasReferences(FName ElementName);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyRealm(FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static bool DestroyElementsByRealm(EGameLogicEditorPanel ElementType, FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static void CreateRealm(FName RealmName);
    
    UFUNCTION(BlueprintCallable)
    static FName ComputeUniqueElementName(const FName& BaseName);
    
    UFUNCTION(BlueprintCallable)
    static FName AddElementToRealm(EGameLogicEditorPanel ElementType, FName RealmName, int32 Index, bool bCopyIndex, int32 IndexToCopy);
    
};

