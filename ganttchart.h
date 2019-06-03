#ifndef GANTTCHART_H
#define GANTTCHART_H
#include <QDateTime>
#include <timeline.h>
#include <iterator.h>

template <class T>
class GanttChart
{
private:
    QDateTime minDate;
    QDateTime maxDate;
    //std::vector<Timeline<T>> *timelines; // <TimelineItem<T>>
    std::vector<Timeline<T>/*, Allocator<Timeline<T>>*/> *timelines;

public:
    GanttChart(){
        this->setMinDate(QDateTime(QDate(2000,1,1), QTime(0,0)));
        this->setMaxDate(QDateTime(QDate(2020,1,1), QTime(0,0)));

        this->timelines = new std::vector<Timeline<T>/*, Allocator<Timeline<T>>*/>;
    }

    ~GanttChart() {}

    void addTimeline(Timeline<T> *timeLine){
        this->timelines->push_back( *timeLine); // было без *
    }

    QDateTime getMinDate() const
    {
        return minDate;
    }
    void setMinDate(const QDateTime &value)
    {
        minDate = value;
    }
    QDateTime getMaxDate() const
    {
        return maxDate;
    }
    void setMaxDate(const QDateTime &value)
    {
        maxDate = value;
    }
    std::vector<Timeline<T>/*, Allocator<Timeline<T>>*/> *getTimelines() const //<TimelineItem<T>>
    {
        return timelines;
    }
    void setTimelines(const std::vector<Timeline<T>/*, Allocator<Timeline<T>>*/> &value) // <TimelineItem<T>>
    {
        timelines = value;
    }

//    typedef Iterator<T>* iterator;

//               iterator begin(){
//                   return new Iterator<T>(timelines, 0);
//               }
//               iterator end(){
//                   return new Iterator<T>(this->timelines, this->timelines->size());
//               }

};

#endif // GANTTCHART_H
