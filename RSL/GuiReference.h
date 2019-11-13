#pragma once
#include <vector>
#include "BaseGui.h"

//Todo: Add a name var to BaseGui and use that to find refs. That way people can have a constantly changing title and still reference a gui via it's name.
//Used to reference a Gui without needing to directly access the Gui std::vector and keep track of each guis index.
template <class T>
class GuiReference
{
public:
    GuiReference() {}
    GuiReference(int Index_, std::vector<BaseGui*>* List_) : Index(Index_), List(List_) { Ready = true; }

    void Set(int Index_, std::vector<BaseGui*>* List_)
    {
        Index = Index_;
        List = List_;
        Ready = true;
    }
    T& Get()
    {
        return *reinterpret_cast<T*>(List->at(Index));
    }
    void Clear()
    {
        Index = -1;
        List = nullptr;
        Ready = false;
    }
    [[nodiscard]] bool IsReady() const
    {
        return Ready;
    }


    GuiReference& operator=(const GuiReference& other)
    {
        if (this == &other)
        {
            return *this;
        }
        Index = other.Index;
        List = other.List;
        Ready = other.Ready;
        return *this;
    }

private:
    int Index = -1; //Index of the gui on the GuiList
    std::vector<BaseGui*>* List = nullptr; //Pointer to the GuiList
    bool Ready = false;
};